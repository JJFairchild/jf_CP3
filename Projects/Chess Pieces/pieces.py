from abc import ABC, abstractmethod

class ChessPiece(ABC):
    def __init__(self, color, position):
        self.color = color
        self.position = position

    # getPosition was useless because I could just use object.position
    
    def formatPosition(self):
        alphabet = "abcdefgh"
        return alphabet[self.position[0]] + str(self.position[1])
    
    def getPieceAt(self, position):
        """Gets the piece at a given position"""
        for piece in self.pieces:
            if piece.position == position:
                return piece
        return False
    
    @abstractmethod
    def canMoveTo(position):
        pass

    @abstractmethod
    def getSymbol(self):
        pass

class Pawn(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def canMoveTo(self, position):
        patpos = self.getPieceAt(position)

        if self.color == "w":
            if (position[0] == self.position[0] and position[1] == self.position[1] + 1):
                if not patpos:
                    return True
            if patpos:
                if patpos.color == "b" and ((position[0] == self.position[0] + 1 and position[1] == self.position[1] + 1) or (position[0] == self.position[0] - 1 and position[1] == self.position[1] + 1)):
                    return True
        else:
            if (position[0] == self.position[0] and position[1] == self.position[1] - 1):
                if not patpos:
                    return True
            if patpos:
                if patpos.color == "w" and ((position[0] == self.position[0] + 1 and position[1] == self.position[1] - 1) or (position[0] == self.position[0] - 1 and position[1] == self.position[1] - 1)):
                    return True
        return False

    def getSymbol(self):
        if self.color == "w":
            return "♙"
        else:
            return "♟"
    
    def __str__(self):
        return "pawn"