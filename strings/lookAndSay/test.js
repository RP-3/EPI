var should = require('should');
var lookAndSay = require('./lookAndSay.js');

describe('lookAndSay', function(){

  it('should be a function', function(){
    lookAndSay.should.be.type('function');
  });

  it('should return a string', function(){
    lookAndSay(1).should.be.type('string');
  });

  it('should return the approproate number from the sequence', function(){
    lookAndSay(0).should.equal('1');
    lookAndSay(1).should.equal('11');
    lookAndSay(2).should.equal('21');
    lookAndSay(3).should.equal('1211');
    lookAndSay(4).should.equal('111221');
    lookAndSay(5).should.equal('312211');
    lookAndSay(6).should.equal('13112221');
  });

});
