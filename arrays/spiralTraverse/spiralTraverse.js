var spiralTraverse = function(array, cb){

  var traversed = {};
  
  function alreadyTraversed(i, j){
    var coords = i.toString() + j.toString();
    if(traversed.hasOwnProperty(coords)){
      return true;
    }else{
      traversed[coords] = true;
      return false;
    }
  }

  function traverseRight(offset){
    for(var i=offset; i<array[0].length -offset; i++){
      if(alreadyTraversed(offset, i)){continue;}
      cb(array[offset][i]);
    }
  }

  function traverseLeft(offset){
    for(var i=array[0].length - offset -2; i>=offset; i--){
      if(alreadyTraversed(array.length - offset -1, i)){continue;}
      cb(array[array.length - offset -1][i]);
    }
  }

  function traverseDown(offset){
    for(var i=offset+1; i<array.length -offset; i++){
      if(alreadyTraversed(i, array[0].length - offset -1)){continue;}
      cb(array[i][array[0].length - offset -1]);
    }
  }

  function traverseUp(offset){
    for(var i=array.length - offset -2; i>=offset+1; i--){
      if(alreadyTraversed(i, offset)){continue;}
      cb(array[i][offset]);
    }
  }

  var orbit = function(offset){
    traverseRight(offset);
    traverseDown(offset);
    traverseLeft(offset);
    traverseUp(offset);
  };

  for(var j=0; j<array.length; j++){
    orbit(j);
  }

};

module.exports = spiralTraverse;
