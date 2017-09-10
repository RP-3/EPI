var should = require('should');
var List = require('./reverseList.js');

describe('reverse', function(){

  it('should exist on the List prototype', function(){
    List.prototype.should.have.property('reverse');
  });

  it('should be a function', function(){
    List.prototype.reverse.should.be.type('function');
  });

  it('should reverse a list of length one', function(){
    var list = new List(0);
    var result = new List(0);
    list.reverse();
    list.should.eql(result);
  });

  it('should reverse a list of length two', function(){
    var list = new List(0);
    list.addToTail(1);

    var result = new List(1);
    result.addToTail(0);
    
    list.reverse();

    list.should.eql(result);
  });

  it('should reverse a list of arbitrary length', function(){
    var list = new List(0);
    for(var i=1; i<21; i++){
      list.addToTail(i);
    }

    var result = new List(20);
    for(var j=19; j>=0; j--){
      result.addToTail(j);
    }

    list.reverse();

    list.should.eql(result);

  });

});
