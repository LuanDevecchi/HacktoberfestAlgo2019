intersection = (a,b) => {
	f = (x,a) => (a.indexOf(x) != -1 ? true : false);
	let result = [];
	for(let x = 0; x < a.length;x++){
		if(f(a[x],b)){
			result.push(a[x])
		};
	}return result;}

console.log(intersection([1,2,3],[0,2,1])); // = {1,2,3}∩{0,2,1} Result: {1,2}
