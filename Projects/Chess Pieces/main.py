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
- Main function
"""

from pieces import *

class ChessGame:
    def __init__(self, pieces=None):
        if pieces is None:
            pieces = []
        self.pieces = pieces # Created a merged list of pieces rather than separating them by color because it was more convenient

    def movePiece(self, piece, position):
        """Moves a piece to a position if it will work. Also includes capture logic."""
        if piece.canMoveTo(self, position):
            target = self.getPieceAt(position)
            if target:
                self.removePiece(target)
            piece.position = position
            return True
        return False

    def removePiece(self, piece):
        """Deletes a piece from the piece list"""
        self.pieces.remove(piece)

    def getColor(self, color): # Decided to leave this method even though it's not being used, since it WOULD be used in a version that had proper checkmating logic.
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
    
    def display(self):
        """Prints the board in a human-readable way."""
        for x in range(8, 0, -1):  # ranks 8 → 1 (top → bottom)
            row = str(x) + " "
            for y in range(1, 9):  # files 1 → 8 (a → h)
                piece = self.getPieceAt((y, x))
                if piece:
                    row += piece.getSymbol() + " "
                else:
                    row += ". "
            print(row)
        print("  a b c d e f g h")  # file labels


def main():
    board = ChessGame(
        pieces=[
            # White pieces
            Rook("w", (1, 1)), Knight("w", (2, 1)), Bishop("w", (3, 1)),
            Queen("w", (4, 1)), King("w", (5, 1)), Bishop("w", (6, 1)),
            Knight("w", (7, 1)), Rook("w", (8, 1)),
            Pawn("w", (1, 2)), Pawn("w", (2, 2)), Pawn("w", (3, 2)),
            Pawn("w", (4, 2)), Pawn("w", (5, 2)), Pawn("w", (6, 2)),
            Pawn("w", (7, 2)), Pawn("w", (8, 2)),

            # Black pieces
            Rook("b", (1, 8)), Knight("b", (2, 8)), Bishop("b", (3, 8)),
            Queen("b", (4, 8)), King("b", (5, 8)), Bishop("b", (6, 8)),
            Knight("b", (7, 8)), Rook("b", (8, 8)),
            Pawn("b", (1, 7)), Pawn("b", (2, 7)), Pawn("b", (3, 7)),
            Pawn("b", (4, 7)), Pawn("b", (5, 7)), Pawn("b", (6, 7)),
            Pawn("b", (7, 7)), Pawn("b", (8, 7)),
        ]
    )

    color = "w"  # White moves first

    while True:
        board.display()
        print(f"{'White' if color == 'w' else 'Black'}'s turn")

        while True:
            # Ask for input in the form 'from to'
            move = input("Enter your move (from to): ").strip().lower()
            try:
                fsquare, tsquare = move.split()
            except ValueError:
                print("Invalid input. Example: 'e2 e4'")
                continue

            # Convert algebraic notation to coordinates
            alphabet = "abcdefgh"
            try:
                fpos = (alphabet.index(fsquare[0]) + 1, int(fsquare[1]))
                tpos = (alphabet.index(tsquare[0]) + 1, int(tsquare[1]))
            except (ValueError, IndexError):
                print("Invalid square. Use a-h and 1-8.")
                continue

            # Error handling
            piece = board.getPieceAt(fpos)
            if not piece:
                print("No piece at that square.")
                continue
            if piece.color != color:
                print("That's not your piece.")
                continue
            if not piece.canMoveTo(board, tpos):
                print("Illegal move for that piece.")
                continue
            break

        # Capture any piece at the destination
        target_piece = board.getPieceAt(tpos)
        if target_piece:
            if isinstance(target_piece, King):
                board.pieces.remove(target_piece)
                board.display()
                print(f"{'White' if color == 'w' else 'Black'} wins!")
                break
            else:
                board.pieces.remove(target_piece)

        # Move the piece
        piece.position = tpos

        # Switch turns
        color = "b" if color == "w" else "w"

main()