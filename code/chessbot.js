// Create a new Chess instance
var chess = new Chess();

// Function to initialize the chessboard
function initializeChessboard() {
    var chessboard = document.getElementById('chessboard');

    for (var i = 0; i < 64; i++) {
        var square = document.createElement('div');
        square.className = 'square ' + getColor(i);
        square.id = 'square-' + i;
        square.addEventListener('click', onSquareClick);
        chessboard.appendChild(square);
    }
}
var board2 = Chessboard('board2', {
    draggable: true,
    dropOffBoard: 'trash',
    sparePieces: true
  })
  
  $('#startBtn').on('click', board2.start)
  $('#clearBtn').on('click', board2.clear)
// Function to handle square click event
function onSquareClick(event) {
    var squareId = event.target.id.split('-')[1];
    var moves = chess.moves({ square: squareId, verbose: true });

    if (moves.length === 0) {
        return; // No valid moves
    }

    // Implement your logic to select the best move from the 'moves' array

    var bestMove = moves[0]; // Placeholder, replace with your logic

    // Make the best move
    chess.move({ from: bestMove.from, to: bestMove.to });

    // Update the UI
    renderChessboard();
}

// Function to render the chessboard
function renderChessboard() {
    for (var i = 0; i < 64; i++) {
        var square = document.getElementById('square-' + i);
        square.textContent = getPiece(i);
    }
}

// Helper function to get the color of a square
function getColor(square) {
    var row = Math.floor(square / 8);
    var col = square % 8;
    return (row % 2 === col % 2) ? 'white' : 'black';
}

// Helper function to get the piece at a square
function getPiece(square) {
    var piece = chess.get(square);
    return piece ? piece.type : '';
}

// Start the game when the Start Game button is clicked
document.getElementById('startBtn').addEventListener('click', function () {
    initializeChessboard();
    renderChessboard();
});

// Reset the game when the Reset Game button is clicked
document.getElementById('resetBtn').addEventListener('click', function () {
    chess.reset();
    renderChessboard();
});
