// Function to shuffle an array
function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

// Function to display products out of order
function displayProductsOutOfOrder() {
  const products = document.querySelectorAll('.product');
  const shuffledProducts = shuffleArray(Array.from(products));
  const productsContainer = document.querySelector('.products-container');
  
  // Remove existing products from the container
  productsContainer.innerHTML = '';
  
  // Add the shuffled products back to the container
  shuffledProducts.forEach(product => {
    productsContainer.appendChild(product);
  });
}

// Add an event listener to the "Shuffle Products" button
const shuffleButton = document.querySelector('#shuffle-button');
shuffleButton.addEventListener('click', displayProductsOutOfOrder);
