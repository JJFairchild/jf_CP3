from abc import ABC, abstractmethod

class ChessPiece(ABC):
    def __init__(self, color, position):
        self.color = color
        self.position = position

    def getPosition(self):
        return self.position
    
    @abstractmethod
    def canMoveTo(nposition):
        pass

    @abstractmethod
    def getSymbol(self):
        pass

class Pawn(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)

    def canMoveTo(nposition):
        print("ghigf")

    def getSymbol(self):
        if self.color == "w":
            return "♙"