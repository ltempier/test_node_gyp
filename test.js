const addon = require('./c++/build/Release/addon');

const factor = 1000000000;

console.time('c++');
console.log(addon.test(factor)); // 'world'
console.timeEnd('c++');

console.time('node');
var count = 0;
for (var a = 0; a < factor; a = a + 1) {
    if (a % 2)
        count += 1;
}
console.log(count);
console.timeEnd('node');
