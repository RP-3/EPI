/*

Write a function that multiplies two positive integers. The only operators
you should use are assignment '=' and bitshifters '>>, <<, |, &, ~, ^'.

You can while-loops, if-statements (if, ||, &&) and functions that you
write yourself. Note: for-loops are a no-no since ++ and -- aren't allowed.

Hint: This is really two problems wrapped into one:
write a helper function that adds two integers together. This should run
in constant time. 

Then consider the multiplication problem separately. It should be possible
to make this, too, run in constant time. 

This is considered a tough problem, so don't despair if you struggle 
with it. If you totally crush it, do a student presentation on it. 

*/

function add(x, y){
  var sum = 0, 
      bit = 1, 
      carryOver = 0, 
      xint = x, 
      yint = y;

  while(bit > 0){
    //fetch just the bit'th bit of each int
    var xBit = xint & bit;
    var yBit = yint & bit;

    //flip the bit'th bit of the sum if any ONE of x, y 
    //or the previous two bits combined (carryOver) are a 1
    sum |= (xBit ^ yBit ^ carryOver);

    //calculate the carryOver
    //if the bit'th bit of both x and y are 1 OR either of them is 1 AND there's already a carryOver
    var temp = (xBit & yBit) | (xBit & carryOver) | (yBit & carryOver);
    carryOver = temp << 1;

    //update the bit pointer
    bit = bit << 1;

  }

  return sum;
}

var multiplySansAdd = function(a, b){
  var result = 0, bit = 1, place = 0;

  while(bit > 0){
    //fetch the bit'th bit of a and b
    var aBit = a & bit;

    //if that bit is set, add b * aBit to sum
    if(aBit){
      result = add(result, b << place);
    }

    //increment the bit and place of the bit
    bit = bit << 1;
    place = add(place, 1);
  }

  return result;

};

module.exports = multiplySansAdd;













