var should = require('should');
var parseInt = require('./parseInt.js');

describe('parseInt', function(){

  it('should be a function', function(){
    parseInt.should.be.type('function');
  });

  it('should return an integer', function(){
    ((parseInt('21')*10)%10).should.equal(0);
    ((parseInt('21.1')*10)%10).should.equal(0);
    ((parseInt('29')*10)%10).should.equal(0);
    ((parseInt('29.9')*10)%10).should.equal(0);
  });

  it('should correctly parse a single character', function(){
    parseInt('2').should.equal(2);
    parseInt('7').should.equal(7);
  });

  it('should correctly parse multiple integers', function(){
    parseInt('369').should.equal(369);
    parseInt('369.1').should.equal(369);
    parseInt('369.9').should.equal(369);
  });

  it('shuld handle commas and spaces', function(){
    parseInt('369,2837.00').should.equal(3692837);
    parseInt('369,28 37.00').should.equal(3692837);
  });

  it('should refuse to parse unrecognised characters', function(){
    parseInt('38YODAtheKingpin0').should.equal(380);
  });

});
