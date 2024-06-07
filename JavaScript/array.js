const numbers=[1,2,4,5,6,7,8,9,10,11];
biggestNumber(numbers);
function printEvenNumbers(numbers) {
    numbers.forEach(num=>{
        if(num%2==0){
            console.log(num);
        }
    });
    console.log("/n");
    for(let i=0;i<numbers.length;i++){
        if(numbers[i]%2==0){
            console.log(numbers[i]);
        }
    }
}



function biggestNumber(numbers){
    const maxNum= Math.max(...numbers);
    console.log(`biggest number is ${maxNum}`);
}
