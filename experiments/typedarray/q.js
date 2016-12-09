var addon = require('bindings')('widlNanAddon')

console.log(addon);

var obj = new addon.MyInterface();

console.log(obj);


var arr = obj.asInt8Array();

console.log(arr);

