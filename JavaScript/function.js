function sum( a, b){
    return a+b;
}

function subtract( a, b){
    return a-b;
}


function calculateArthimetic(a,b,arthimeticCallBackFunction){
    const ans= arthimeticCallBackFunction(a,b);
    return ans;
}

console.log(calculateArthimetic(3,4,subtract));