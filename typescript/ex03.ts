// let obj: any = {x:0};
// obj.foo();
// obj();
// obj.bar = 100;
// obj = "hello";
// const n: number = obj;

// let myName: string = "Alice";



// Argument of type 'number' is not assignable to parameter of type 'string'.
// function greet2(name: string){
//     console.log("hello, " + name.toUpperCase() + "!!");
// }
// greet2(42);



// function getFavoriteNumber(): number {
//     return 25;
// }



// const names = ["Alice", "Bob", "Eve"];
// names.forEach(function(s){
//     console.log(s.toUpperCase());
// });




// function printCoord(pt: { x: number, y: number }) {
//     console.log("The coordinate's x value is " + pt.x);
//     console.log("The coordinate's y value is " + pt.y);
// }
// printCoord({ x: 3, y: 7});



// function printName(obj: { first: string; last?: string }){
// }
// printName({ first: "Bob" });
// printName({ first: "Alice", last: "Alisson"});



// Object is possibly 'undefined'
// function printName(obj: { first: string; last?: string }){
//     console.log(obj.last.toUpperCase());
//     if (obj.last !== undefined){
//         console.log(obj.last.toUpperCase());
//     }
//     console.log(obj.last?.toUpperCase());
// }
// printName({ first: "Bob" });
// printName({ first: "Alice", last: "Alisson"});



// Argument of type '{ myID: number; }' is not assignable to parameter of type 'string | number'.
// Type '{ myID: number; }' is not assignable to type 'number'.
// function printId(id: number | string){
//     console.log("your id is " + id);
// }
// printId(101);
// printId("202");
// printId({ myID: 22342 });



// Property 'toUpperCase' does not exist on type 'string | number'.
// Property 'toUpperCase' does not exist on type 'number'.
// function printId( id: number | string){
//     console.log(id.toUpperCase());
// }



// function printId( id: number | string){
//     if (typeof id === "string"){
//         console.log(id.toUpperCase());
//     } else{
//         console.log(id);
//     }
// }



// function welcomePeople(x: string[] | string){
//     if (Array.isArray(x)){
//         console.log("hello, " + x.join(" and "));
//     } else{
//         console.log("welcome lone traveler " + x);
//     }
// }



// function getFirstThree(x: number[] | string){
//     return x.slice(0, 3);
// }



// type Point = {
//     x: number;
//     y: number;
// };
// function printCoord(pt: Point){
//     console.log("x value is " + pt.x);
//     console.log("y value is " + pt.y);
// }
// printCoord({ x: 100, y: 100});



// type UserInputSanitizedString = string;
// function sanitizeInput(str: string): UserInputSanitizedString{
//     return sanitizeInput(str);
// }
// let userInput = sanitizeInput(getInput());
// userInput = "new input";



// interface Point {
//     x: number;
//     y: number;
// }
// function printCoord(pt: Point){
//     console.log("x value is " + pt.x);
//     console.log("y value is " + pt.y);
// }
// printCoord({ x: 100, y: 100});


// const myCanvas = document.getElementById("main_canvas") as HTMLCanvasElement
// console.log(myCanvas);


// const myCanvas = <HTMLCanvasElement>document.getElementById("main_canvas");
// console.log(myCanvas);



// Conversion of type 'string' to type 'number' may be a mistake because neither type sufficiently
// overlaps with the other. If this was intentional, convert the expression to 'unknown' first.
// const x = "hello" as number



// let changingString = "hello world";
// changingString = "Ola Mundo";
// changingString;
// console.log(changingString);



// const constantString = "hello world";
// constantString;



//  Type '"howdy"' is not assignable to type '"hello"'.
// let x: "hello" = "hello";
// x = "hello";
// x = "howdy";



// Argument of type '"centre"' is not assignable to parameter of type '"left" | "right" | "center"'
// function printText(s: string, alignment: "left" | "right" | "center"){
// }
// printText("hello world", "left");
// printText("hello", "centre");



// function compare(a: string, b:string): -1 | 0 | 1{
//     return a===b ? 0 : a > b ? 1 : -1;
// }



// Argument of type '"ausdfs"' is not assignable to parameter of type 'Options | "auto"'.
// interface Options {
//     width: number;
// }
// function configure(x: Options | "auto"){
// }
// configure({ width: 100});
// configure("auto");
// configure("ausdfs");


