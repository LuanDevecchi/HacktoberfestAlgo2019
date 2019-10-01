// The formula verifies a number against its included check digit, which is usually appended to a partial account number to generate the full account number. This number must pass the following test:

// From the rightmost digit (excluding the check digit) and moving left, double the value of every second digit. The check digit is neither doubled nor included in this calculation; the first digit doubled is the digit located immediately left of the check digit. If the result of this doubling operation is greater than 9 (e.g., 8 × 2 = 16), then add the digits of the result (e.g., 16: 1 + 6 = 7, 18: 1 + 8 = 9) or, alternatively, the same final result can be found by subtracting 9 from that result (e.g., 16: 16 − 9 = 7, 18: 18 − 9 = 9).

// Take the sum of all the digits.

// If the total modulo 10 is equal to 0 (if the total ends in zero) then the number is valid according to the Luhn formula; otherwise it is not valid.

// A fórmula verifica um número com relação ao dígito de verificação incluído, que geralmente é anexado a um número parcial da conta para gerar o número completo da conta. Esse número deve passar no seguinte teste:

//// No dígito mais à direita (excluindo o dígito de verificação) e movendo-se para a esquerda, dobre o valor de cada segundo dígito.

//O dígito de verificação não é dobrado nem incluído neste cálculo; o primeiro dígito dobrado, é o dígito localizado imediatamente à esquerda do dígito de verificação. Se o resultado dessa operação de duplicação for maior que 9 (por exemplo, 8 × 2 = 16), adicione os dígitos do resultado (por exemplo, 16: 1 + 6 = 7, 18: 1 + 8 = 9) ou, alternativamente, , o mesmo resultado final pode ser encontrado subtraindo 9 desse resultado (por exemplo, 16: 16 - 9 = 7, 18: 18 - 9 = 9).

// Pegue a soma de todos os dígitos.

// Se o módulo total 10 for igual a 0 (se o total terminar em zero), o número é válido de acordo com a fórmula de Luhn; caso contrário, não é válido.

function isValidCreditCard(card) {
    let clean_card = card.replace(/\D/g, "").split("");
  
    for (let i = clean_card.length - 2; i >= 0; i -= 2) {
      let result = (clean_card[i] * 2).toString();
  
      if (result.length === 2) {
        result = parseInt(result[0]) + parseInt(result[1]);
      }
      clean_card[i] = result;
    }
    let sum = 0;
    for (const element of clean_card) {
      sum += parseInt(element);
    }
    return sum > 0 && sum % 10 === 0;
  }
  
  //tests
  
  // const valid_credit_cards = [
  //     "799 273 987 13",
  //     "378734493671000",
  //     "3714-4963-5398-431",
  //     "5610XXX..5910--810!18250",
  //     "30569309025904",
  //     "385 2000   0023 237",
  //     "6011111111111117",
  //     "6011000990139424",
  //     "353 0111 3333 00000",
  //     "356600 woop woop 2020360505",
  //     "5555555555554444",
  //     "5105105105105100"
  // ]
  
  // for (const valid of valid_credit_cards) {
  //     console.log(isValidCreditCard(valid))
  // }
  
  // const invalid_credit_cards = [
  //     "799 223 987 13",
  //     "3787786493671000",
  //     "3724-4963-5398-431",
  //     "5610XX3..5910--810!18250",
  //     "0305699025904",
  //     "385 2000   0011123 237",
  //     "6011111111117",
  //     "60190139424",
  //     "353 0111 3333 00100",
  //     "3566043 woop woop 2020360505",
  //     "55553555555554444",
  //     "5105205105105100"
  // ]
  
  // for (const invalid of invalid_credit_cards) {
  //     console.log(isValidCreditCard(invalid))
  // }
  
  