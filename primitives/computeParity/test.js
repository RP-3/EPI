var should = require('should');
var computeParity = require('./computeParity.js');

var timer = function(cb, repeats){
  var start = process.hrtime();
  var args = Array.prototype.slice.call(arguments, 2);
  for(var i=0; i<repeats; i++){
    cb.apply(null, args);
  }
  return process.hrtime(start);
};


describe('computeParity', function(){

  it('should be a function', function(){
    computeParity.should.be.type('function');
  });

  it('should always return one or zero', function(){
    var options = {1: true, 0: true};
    options.hasOwnProperty(computeParity(1)).should.be.true;
    options.hasOwnProperty(computeParity(0)).should.be.true;
    options.hasOwnProperty(computeParity(2)).should.be.true;
    options.hasOwnProperty(computeParity(3)).should.be.true;
    options.hasOwnProperty(computeParity(5)).should.be.true;
    options.hasOwnProperty(computeParity(10)).should.be.true;
    options.hasOwnProperty(computeParity(99)).should.be.true;
    options.hasOwnProperty(computeParity(1022)).should.be.true;
    options.hasOwnProperty(computeParity(792938)).should.be.true;
  });

  it('should correctly compute the parity of a given integer', function(){
    computeParity(1).should.equal(1);
    computeParity(2).should.equal(1);
    computeParity(3).should.equal(0);
    computeParity(4).should.equal(1);
    computeParity(5).should.equal(0);
    computeParity(8).should.equal(1);
    computeParity(16).should.equal(1);
    computeParity(32).should.equal(1);
    computeParity(9).should.equal(0);
    computeParity(17).should.equal(0);
    computeParity(33).should.equal(0);
  });

});
