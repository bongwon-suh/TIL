// This expression is not callable.
// const message = "hello world";
// message.toLowerCase();
// message();



// Property 'location' does not exist on type '{ name: string; age: number; }'
// const user2 = {
//     name: "Daniel",
//     age: 26,
// };
// user2.location;



// Operator '<' cannot be applied to types '() => number' and 'number'.
// function flipCoin() {
//     return Math.random < 0.5;
// }


//This condition will always return 'false' since the types '"a"' and '"b"' have no overlap.
// const value = Math.random() < 0.5? "a":"b";
// if(value!=="a"){}
// else if(value === "b"){}



// Expected 2 arguments, but got 1.
// function greet(person, date){
//     console.log(`hello ${person}, today is ${date}`);
// }
// greet("Brendan");



//Argument of type 'string' is not assignable to parameter of type 'Date'.
// function greet(person: string, date: Date){
//     console.log(`hello ${person}, today is ${date.toDateString()}!`);
// }
// greet("Maddison", Date());


function greet(person: string, date: Date){
    console.log(`hello ${person}, today is ${date.toDateString()}!`);
}
greet("Maddison", new Date());