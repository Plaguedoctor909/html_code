import random
import chess

def is_valid_move(board, move):
    return move in board.legal_moves

def make_random_move(board):
    legal_moves = list(board.legal_moves)
    return random.choice(legal_moves)

def play_chess():
    # Create a chess board
    board = chess.Board()

    try:
        while not board.is_game_over():
            print(board)
            
            # Check if it's the bot's turn
            if board.turn == chess.WHITE:
                print("Bot is thinking...")
                
                # Make a random move for the bot
                bot_move = make_random_move(board)
                board.push(bot_move)
            else:
                # Wait for the user to enter their move
                user_move = input("Enter your move (e.g., e2e4): ")
                try:
                    # Attempt to parse and apply the move
                    move = chess.Move.from_uci(user_move)
                    if is_valid_move(board, move):
                        board.push(move)
                    else:
                        print("Invalid move. Try again.")
                except ValueError:
                    print("Invalid move. Try again.")
            
        print("Game over. Result:", board.result())
    except KeyboardInterrupt:
        print("\nGame interrupted by the user.")

if __name__ == "__main__":
    play_chess()
