var should = require('should');
var encodeExcel = require('./encodeExcel.js');


describe('encodeExcel', function(){

  it('should be a function', function(){
    encodeExcel.should.be.type('function');
  });

  it('should return the correct encoding for single chars', function(){
    encodeExcel('A').should.equal(1);
    encodeExcel('B').should.equal(2);
    encodeExcel('C').should.equal(3);
    encodeExcel('D').should.equal(4);
    encodeExcel('E').should.equal(5);
    encodeExcel('K').should.equal(11);
    encodeExcel('Y').should.equal(25);
    encodeExcel('Z').should.equal(26);
  });

  it('should return the correct encoding for multiple chars', function(){
    encodeExcel('AA').should.equal(27);
    encodeExcel('AB').should.equal(28);
    encodeExcel('AZ').should.equal(52);
    encodeExcel('BA').should.equal(53);
    encodeExcel('ZZ').should.equal(702);
    encodeExcel('AAA').should.equal(703);
  });

});
