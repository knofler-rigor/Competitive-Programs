'use strict';
const fs = require('fs');
process.stdin.resume();
process.stdin.setEncoding('utf-8');
let inputString = '';
let currentLine = 0;
process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});
process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});
function readLine() {
    return inputString[currentLine++];
}

function  findSum(numbers,  queries)  {
  let  result  =   [];    
  let  subArraySum  =   [];    
  let  countZero  =  numbers[0]  ==  0 ? 1 : 0;    
  let  zeroArr  =   [];    
  zeroArr[0] =  countZero;    
  subArraySum[0]  =  numbers[0];    
  for (let  i = 1;  i <= numbers.length - 1; i++) {               
    if (numbers[i]  ==  0) {            
      countZero++;            
      zeroArr[i]  =  countZero;        
    } 
    else  {            
      zeroArr[i]  =  countZero;         
    }         
    subArraySum[i] = subArraySum[i - 1] + numbers[i];    
  }    
  for (let  q  of  queries)  {            
    if (q.length  ==  3)  {            
      let  i  =  q[0];            
      let  j  =  q[1];            
      let  x  =  q[2];            
      let  sum  =  0;                       
      sum  =  subArraySum[j - 1] - ((i - 2  <  0 )  ?  0  :  subArraySum[i - 2]);             
      sum  =  sum  +  (zeroArr[j - 1] - ((i - 2  <  0 )  ?  0  :  zeroArr[i - 2])) * x;            
      result.push(sum);        
    }                  
  }    
  return  result;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const numbersCount = parseInt(readLine().trim(), 10);

    let numbers = [];

    for (let i = 0; i < numbersCount; i++) {
        const numbersItem = parseInt(readLine().trim(), 10);
        numbers.push(numbersItem);
    }

    const queriesRows = parseInt(readLine().trim(), 10);

    const queriesColumns = parseInt(readLine().trim(), 10);

    let queries = Array(queriesRows);

    for (let i = 0; i < queriesRows; i++) {
        queries[i] = readLine().replace(/\s+$/g, '').split(' ').map(queriesTemp => parseInt(queriesTemp, 10));
    }

    const result = findSum(numbers, queries);

    ws.write(result.join('\n') + '\n');

    ws.end();
}
