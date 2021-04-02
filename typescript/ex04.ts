// Operator '+' cannot be applied to types 'string | number' and 'number'.
// function padLeft(padding: number | string, input: string): string{
//     throw new Error("Not implementd yet!");

//     return new Array(padding +1).join(" ") + input;
// }



// function padLeft(padding: number | string, input: string){
//     if (typeof padding === "number"){
//         return new Array(padding+1).join(" ") + input;
//     }
//     return padding + input;
// }



// Object is possibly 'null'.
// function printAll(strs: string | string[] | null){
//     if (typeof strs === "object"){
//         for (const s of strs){
//             console.log(s);
//         }
//     } else if (typeof strs === "string") {
//         console.log(strs);
//     }
//     else{

//     }
// }



// function printall(strs: string | string[] | null){
//     if (strs && typeof strs === "object"){
//         for (const s of strs){
//             console.log(s);
//         }
//     } else if (typeof strs === "string"){
//         console.log(strs);
//     }
// }



// function multiplyAll(
//     values: number[] | undefined,
//     factor: number
// ): number[] | undefined {
//     if (!values) {
//         return values
//     }
//     else {
//         return values.map((x) => x*factor);
//     }
// }



// function example(x: string | number, y: string | boolean) {
//     if (x === y){
//         x.toUpperCase();
//         y.toLowerCase();
//     }
//     else{
//         console.log(x);
//         console.log(y);
//     }
// }



// function printAll(strs: string | string[] | null){
//     if (strs !== null) {
//         if (typeof strs === "object"){
//             for (const s of strs){
//                 console.log(s);
//             }
//         } else if (typeof strs === "string"){
//             console.log(strs);
//         }
//     }
// }



// interface Container {
//     value: number | null | undefined;
// }
// function mutiplyValue(container: Container, factor: number){
//     if (container.value != null) {
//         console.log(container.value);
//         container.value *= factor;
//         console.log(container.value);
//     }
// }



// function logValue(x: Date | string){
//     if (x instanceof Date){
//         console.log(x.toUTCString());
//     } else {
//         console.log(x.toUpperCase());
//     }
// }



// let x= Math.random() < 0.5 ? 10 :"hello world";
// console.log(x);
// x = 1;
// console.log(x);
// x = "goodbye";
// console.log(x);
// Type 'boolean' is not assignable to type 'string | number'
// x = true;



// function padLeft(padding: number | string, input: string){
//     if (typeof padding === "number"){
//         return new Array(padding + 1).join(" ") + input;
//     }
//     return padding + input;
// }



