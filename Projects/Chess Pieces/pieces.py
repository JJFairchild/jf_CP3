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