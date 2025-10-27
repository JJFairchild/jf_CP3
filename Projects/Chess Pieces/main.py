# Jonas Fairchild, Chess Pieces

"""
Lesson 2: Abstraction
LESSON I CAN: I CAN create abstract classes

By the end of this lesson you will be able to:
- Define Abstract classes
- Determine WHEN to use an abstract class
- Distinguish between abstract and concrete methods
- Create abstract classes

State Standards:
    STRAND 5: Students will design and implement advanced object oriented concepts.

        STANDARD 1: Implement object-oriented programs

            - Create classes with minimal extraneous relationships (high cohesion and low coupling)

            - Demonstrate and use composition and aggregation (HAS-A) relationships

            - Demonstrate the use of class variables (static variables) 

INSTRUCTIONS:
- Create the base classes needed to build a chess game (Note: you are not building chess all the way to the end!). Use the class diagram below to create your code!
- Once all of your classes are set up create the correct number of pieces for each player, set them up on the board, move 5 different pieces. 

KEY REMINDERS:
- Follow the provided class diagram exactly 
- Implement ChessPiece as an abstract class 
- Create all six concrete piece classes (Pawn, Rook, Knight, Bishop, Queen, King) 
- Implement canMoveTo(), getSymbol(), setPosition(), and getColor() methods 
- Create ChessGame class with whitePieces and blackPieces lists 
- Implement movePiece(), removePiece(), getPiecesLeft(), and getPieceAt() in ChessGame 
- Create correct number of pieces for each player 
- Set up pieces in starting positions 
- Demonstrate moving 5 different pieces 
- Implement basic move validation for each piece type 
- Use removePiece() method for capturing 
- Put each class in its own file 
- Add comments to explain your code 
- Test each piece type for correct movement 
- Focus on core functionality over advanced game logic

HOW TO SUBMIT:
- Submit your assignment link on canvas
"""

"""
TODO:
- Capture logic in movePiece()
- Classes for other pieces
- Display function
- Main function
"""

from pieces import *

class ChessGame:
    def __init__(self, pieces=None):
        if pieces is None:
            pieces = []
        self.pieces = pieces # Created a merged list of pieces rather than separating them by color because it was more convenient

    def movePiece(self, piece, position):
        """Moves a piece to a position if it will work."""
        if piece.canMoveTo(self, position):
            target = self.getPieceAt(position)
            if target:
                self.removePiece(target)
            piece.position = position
            return True

    def removePiece(self, piece):
        """Deletes a piece from the piece list"""
        self.pieces.remove(piece)

    def getPiecesLeft(self, color):
        """Getter function to return the list of pieces of a color"""
        pieces = []
        for piece in self.pieces:
            if piece.color == color:
                pieces.append(piece)
        return pieces
        
    def getPieceAt(self, position):
        """Gets the piece at a given position"""
        for piece in self.pieces:
            if piece.position == position:
                return piece
        return None