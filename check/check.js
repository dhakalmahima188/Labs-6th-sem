class Animal {};
class Dog extends Animal {};
function walk(a) {
  console.log("dog is walking");
}
function walk(a) {
  console.log("an animal is walking");
}

function f(a) {
  walk(a);
}

const d = new Dog();
f(d);
