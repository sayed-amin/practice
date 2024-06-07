const people = [
    { firstName: 'John', lastName: 'Doe', gender: "male" },
    { firstName: 'Jane', lastName: 'Smith', gender: 'female' },
    { firstName: 'Mike', lastName: 'Johnson', gender: 'male' },
];
printMaleFirstNames2(people);
people.reverse();
console.log(people);
function printMaleFirstNames1(people) {
    people.forEach(person => {
        if (person.gender === 'male') {
            console.log(person.firstName);
        }
    });
}

function printMaleFirstNames2(people) {
   for(let i=0;i<people.length;i++){
        if(people[i].gender=='male'){
            console.log(people[i].firstName);
        }
   }
}