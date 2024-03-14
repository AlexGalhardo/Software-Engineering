const movie1 = { name: 'Oppenheimer', points: 0 },
      movie2 = { name: 'Barbie', points: 0 },
      movie3 = { name: 'Poor Things', points: 0 },
      movie4 = { name: 'Godzilla Minus One', points: 0 },
      movie5 = { name: 'Killers of the flower moon', points: 0 },
      movie6 = { name: 'Anatomy of a Fall', points: 0 },
      movie7 = { name: 'American Fiction', points: 0 },
      movie8 = { name: 'Maestro', points: 0 },
      movie9 = { name: 'The Holdvoers', points: 0 },
      movie10 = { name: 'The Zone of Interest', points: 0 };

let moviesNominees = [movie1, movie2, movie3, movie4, movie5, movie6, movie7, movie8, movie9, movie10]

function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
}

for (let i = 0; i < 1000; i++) {
    let shuffledMovies = shuffleArray([...moviesNominees]);
  
    for (let j = 0; j < shuffledMovies.length; j++) {
        shuffledMovies[j].points += 10 - j;
    }
}

moviesNominees.sort((a, b) => b.points - a.points);

moviesNominees.forEach(movie => {
    console.log(`${movie.name}: ${movie.points} points`);
});
