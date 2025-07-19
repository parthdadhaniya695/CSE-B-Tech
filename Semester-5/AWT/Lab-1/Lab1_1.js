let x = 6;
let node = 0;



for (let index = 1; index <= x; index++) {
    if (x % index == 0) {
        node++;
    }
}

if (node == 2) {
    console.log('Your number is prime');
} else {
    console.log('Number is not prime');
}
