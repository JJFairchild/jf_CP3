from abc import ABC, abstractmethod

class ChessPiece(ABC):
    def __init__(self, color, position):
        self.color = color
        self.position = position

    # getPosition was useless because I could just use object.position
    
    def formatPosition(self):
        """Returns the string that corresponds to a piece's coordinate"""
        alphabet = "abcdefgh"
        return alphabet[self.position[0] - 1] + str(self.position[1])

    # Moved getPieceAt to the ChessGame class because it was more convenient

    @abstractmethod
    def canMoveTo(self, board, position):
        pass

    @abstractmethod
    def getSymbol(self):
        pass

    @abstractmethod
    def __str__(self):
        pass

class Pawn(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def canMoveTo(self, board, position):
        """Returns whether a pawn can move to a given position."""
        patpos = board.getPieceAt(position) # Piece at the position the pawn is moving to

        # Ensure target square is on the board
        if not (1 <= position[0] <= 8 and 1 <= position[1] <= 8):
            return False
        
        if self.color == "w": # White's movement
            # One square forward
            if position == (self.position[0], self.position[1] + 1) and not patpos:
                return True

            # Two squares forward from starting rank
            if (
                position == (self.position[0], self.position[1] + 2)
                and self.position[1] == 2
                and not patpos
                and not board.getPieceAt((self.position[0], self.position[1] + 1))
            ):
                return True

            # Captures
            if patpos and patpos.color == "b":
                if position in [
                    (self.position[0] + 1, self.position[1] + 1),
                    (self.position[0] - 1, self.position[1] + 1),
                ]:
                    return True

        else:  # Black's movement
            # One square forward
            if position == (self.position[0], self.position[1] - 1) and not patpos:
                return True

            # Two squares forward from starting rank
            if (
                position == (self.position[0], self.position[1] - 2)
                and self.position[1] == 7
                and not patpos
                and not board.getPieceAt((self.position[0], self.position[1] - 1))
            ):
                return True

            # Captures
            if patpos and patpos.color == "w":
                if position in [
                    (self.position[0] + 1, self.position[1] - 1),
                    (self.position[0] - 1, self.position[1] - 1),
                ]:
                    return True
        return False

    def getSymbol(self):
        """Returns the symbol corresponding to a pawn."""
        if self.color == "w":
            return "♙"
        else:
            return "♟"
    
    def __str__(self):
        return "pawn"
    
class Rook(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def canMoveTo(self, board, position):
        """Returns whether a rook can move to a given position."""
        patpos = board.getPieceAt(position) # Piece at the position the pawn is moving to

        # Ensure target square is on the board
        if not (1 <= position[0] <= 8 and 1 <= position[1] <= 8):
            return False
        
        # Movement (color has no effect)
        if position[0] == self.position[0] and not position[1] == self.position[1]: # y (up/down) movement
            step = 1 if position[1] > self.position[1] else -1
            for y in range(self.position[1] + step, position[1], step): # Check every square between the current square and the target square to see if the move is valid
                if board.getPieceAt((self.position[0], y)):
                    return False
                
        elif not position[0] == self.position[0] and position[1] == self.position[1]: # x (left/right) movement
            step = 1 if position[0] > self.position[0] else -1
            for x in range(self.position[0] + step, position[0], step):
                if board.getPieceAt((x, self.position[1])):
                    return False
        else:
            return False
    
        if not patpos:
            return True
        return patpos.color != self.color # Return whether the piece can be captured
    
    def getSymbol(self):
        """Returns the symbol corresponding to a rook."""
        if self.color == "w":
            return "♖"
        else:
            return "♜"
    
    def __str__(self):
        return "rook"
    
class Knight(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)
    
    def canMoveTo(self, board, position):
        """Returns whether a knight can move to a given position."""
        patpos = board.getPieceAt(position) # Piece at the position the pawn is moving to

        # Ensure target square is on the board
        if not (1 <= position[0] <= 8 and 1 <= position[1] <= 8):
            return False

        # List of all relative move offsets for a knight
        moves = (
            (2, 1), (1, 2),
            (-1, 2), (-2, 1),
            (-2, -1), (-1, -2),
            (1, -2), (2, -1),
        )

        for move in moves:
            target = (self.position[0] + move[0], self.position[1] + move[1])
            if position == target:
                if not patpos:
                    return True
                return patpos.color != self.color
        return False
    
    def getSymbol(self):
        """Returns the symbol corresponding to a knight."""
        if self.color == "w":
            return "♘"
        else:
            return "♞"
    
    def __str__(self):
        return "knight"
    
class Bishop(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)
    
    def canMoveTo(self, board, position):
        """Returns whether a bishop can move to a given position."""
        patpos = board.getPieceAt(position)

        # Ensure target square is on the board
        if not (1 <= position[0] <= 8 and 1 <= position[1] <= 8):
            return False

        # Change in x and y, required for diagonal calculations
        dx = position[0] - self.position[0]
        dy = position[1] - self.position[1]

        # Check for diagonal movement
        if abs(dx) != abs(dy) or dx == 0:
            return False

        # Determine step direction (both directions needed because of diagonal movement)
        step_x = 1 if dx > 0 else -1
        step_y = 1 if dy > 0 else -1

        # Check each square between current position and target
        x, y = self.position
        for _ in range(1, abs(dx)):
            x += step_x
            y += step_y
            if board.getPieceAt((x, y)):
                return False

        if not patpos:
            return True
        return patpos.color != self.color  # Capture enemy piece
    
    def getSymbol(self):
        """Returns the symbol corresponding to a bishop."""
        if self.color == "w":
            return "♗"
        else:
            return "♝"
    
    def __str__(self):
        return "bishop"
    
class Queen(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def canMoveTo(self, board, position):
        """Returns whether a queen can move to a given position."""
        patpos = board.getPieceAt(position)

        # Ensure target square is on the board
        if not (1 <= position[0] <= 8 and 1 <= position[1] <= 8):
            return False

        # Change in x and y
        dx = position[0] - self.position[0]
        dy = position[1] - self.position[1]

        # Movement
        if dx == 0 and dy != 0:  # vertical
            step_x = 0
            step_y = 1 if dy > 0 else -1
        elif dy == 0 and dx != 0:  # horizontal
            step_x = 1 if dx > 0 else -1
            step_y = 0
        elif abs(dx) == abs(dy) and dx != 0:  # diagonal
            step_x = 1 if dx > 0 else -1
            step_y = 1 if dy > 0 else -1
        else:
            return False  # not a valid queen move

        # Check the path for blocking pieces
        x, y = self.position
        while (x + step_x, y + step_y) != position:
            x += step_x
            y += step_y
            if board.getPieceAt((x, y)):
                return False

        if not patpos:
            return True
        return patpos.color != self.color # Capture enemy piece

    def getSymbol(self):
        """Returns the symbol corresponding to a queen."""
        return "♕" if self.color == "w" else "♛"

    def __str__(self):
        return "queen"
    
class King(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def canMoveTo(self, board, position):
        """Returns whether the king can move to a given position."""
        patpos = board.getPieceAt(position)

        # Ensure target square is on the board
        if not (1 <= position[0] <= 8 and 1 <= position[1] <= 8):
            return False

        # List of all possible relative move offsets for a king
        moves = (
            (-1, 1), (0, 1), (1, 1),
            (-1, 0),        (1, 0),
            (-1, -1), (0, -1), (1, -1)
        )

        for move in moves:
            target = (self.position[0] + move[0], self.position[1] + move[1])
            if position == target:
                for piece in board.pieces: # Check if the king would move into check
                    if piece.color != self.color and piece.canMoveTo(board, target):
                        return False
                    
                if not patpos:
                    return True
                return patpos.color != self.color
        return False

    def getSymbol(self):
        """Returns the symbol corresponding to a king."""
        return "♔" if self.color == "w" else "♚"

    def __str__(self):
        return "king"