const main = () => {
    console.log(estimateNumberPI());
}

const estimateNumberPI = () => {
    let coPrime = 0;
    let total = 0;
    for (let i = 0; i < 1_000_000_000; i++) {
        const firstNumber = getRandomInt(10_000, 100_000);
        const secondNumber = getRandomInt(10_000, 100_000);
        if (gcd(firstNumber, secondNumber) === 1) {
            coPrime++;
        }
        total++;
    }
    return calculate(coPrime, total);
}

const calculate = (coPrime, total) => {
    const ratio = coPrime / total;
    return Math.sqrt(6 / ratio);
}

const gcd = (a, b) => {
    if (b > a) {
        [a, b] = [b, a];
    }
    const m = a % b;
    if (m === 0) {
        return b;
    } else {
        return gcd(b, m);
    }
}
const getRandomInt = (min, max) => Math.floor((Math.random() * (max - min)) + min);

main();
