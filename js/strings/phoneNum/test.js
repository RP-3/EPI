var should = require('should');
var phoneNum = require('./phoneNum.js');

describe('phoneNum', function(){

  it('should be a function', function(){
    phoneNum.should.be.type('function');
  });

  it('should return all possible letters from a single number', function(){
    phoneNum('2').should.containEql("A");
    phoneNum('2').should.containEql("B");
    phoneNum('2').should.containEql("C");
  });

  it('should return the correct number of letters', function(){
    phoneNum('2').length.should.equal(3);
  });

  it('should return all possible letters from multiple digits', function(){
    phoneNum('22').should.containEql("AA");
    phoneNum('22').should.containEql("AB");
    phoneNum('22').should.containEql("AC");
    phoneNum('22').should.containEql("BA");
    phoneNum('22').should.containEql("BB");
    phoneNum('22').should.containEql("BC");
    phoneNum('22').should.containEql("CA");
    phoneNum('22').should.containEql("CB");
    phoneNum('22').should.containEql("CC");
  });

});
