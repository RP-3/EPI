var should = require('should');
var Node = require('./merge.js');

var genList1 = function(){
  var list = new Node(2, null);
  list.addToTail(3);
  list.addToTail(9);
  list.addToTail(11);
  return list;
};

var genList2 = function(){
  var list = new Node(5, null);
  list.addToTail(7);
  list.addToTail(10);
  list.addToTail(12);
  return list;
};

describe('merge', function(){

  it('should exist on the Node prototype', function(){
    Node.prototype.should.have.property('merge');
  });

  it('should be a function', function(){
    Node.prototype.merge.should.be.type('function');
  });

  it('should merge a single Node less than the start into the correct position', function(){
    var list = genList1();

    var result = new Node(0, null);
    result.addToTail(2);
    result.addToTail(3);
    result.addToTail(9);
    result.addToTail(11);

    var newStart = new Node(0, null);

    list.merge(newStart);
    newStart.should.eql(result);
  });

  it('should merge a single node greater than the start into the correct position', function(){
    var list = genList1();

    var result = new Node(2, null);
    result.addToTail(3);
    result.addToTail(4);
    result.addToTail(9);
    result.addToTail(11);

    var newStart = new Node(4, null);

    list.merge(newStart);
    list.should.eql(result);
  });

  it('should merge multiple Nodes into their correct positions', function(){
    var list = genList1();

    var result = new Node(2, null);
    result.addToTail(3);
    result.addToTail(5);
    result.addToTail(7);
    result.addToTail(9);
    result.addToTail(10);
    result.addToTail(11);
    result.addToTail(12);

    list.merge(genList2());
    list.should.eql(result);

  });

});
