const readline = require('readline');
const { StringDecoder } = require('string_decoder');

const r1 = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function greetPerson(){
    r1.question('Enter you first name: ',(firstName)=>{
        r1.question('Enter you last name: ',(lastName)=>{
           r1.question('Enter you gender: ',(Gender)=>{
                if(Gender.toLowerCase === 'male'){
                    console.log(`Hello, MRs ${lastName}`);
                }else if(Gender.toLowerCase === 'female'){
                    console.log(`Hello, Ms ${lastName}`);
                }else{
                    console.log(`hello ${firstName} ${lastName}`);
                }
                r1.close();
           });
        });
    });
}

greetPerson();