var should = require('should');
var longestPalindrome = require('./longestPalindrome.js');

var string = "My dad is a racecar athlete";

describe('longestPalindrome', function(){

  it('should be a function', function(){
    longestPalindrome.should.be.type('function');
  });

  it('should return a string', function(){
    longestPalindrome(string).should.be.type('string');
  });

  it('should find the longest palindrome in the string', function(){
    longestPalindrome(string).should.equal("a racecar a");
  });

});
