// to run: node toRomanNum.js

const toRomanNum = num => {
  const romanObj = {
    1000: "M",
    900: "CM",
    500: "D",
    400: "CD",
    100: "C",
    90: "XC",
    50: "L",
    40: "XL",
    10: "X",
    9: "IX",
    5: "V",
    4: "IV",
    1: "I"
  };
  const keys = Object.keys(romanObj).sort((a, b) => b - a);
  let output = "";

  const innerLoop = () => {
    for (var i = 0; i < keys.length; i++) {
      if (num >= keys[i]) {
        output += romanObj[keys[i]];
        num -= keys[i];
        return;
      }
    }
  };
  while (num > 0) {
    innerLoop();
  }
  return output;
};

console.log(toRomanNum(33)); // XXXIII
// console.log(toRomanNum(41)); // XLI
// console.log(toRomanNum(76)); // LXXVI
// console.log(toRomanNum(376)); //CCCLXXVI
// console.log(toRomanNum(0)); // ""
// console.log(toRomanNum(999)); // CMXCIX
// console.log(toRomanNum(1000)); // M
