string encode(string src)
{     
  //Your code here 
  int n = src.size();
  string s = "";
  int count = 1;
  
  for(int i=0; i<=n-2; i++){
      if(src[i] == src[i+1]){
          count = count + 1; // count same char
      }
      else{
          s += src[i];
          s += to_string(count);
          count = 1;
      }
  }
  s += src[n-1];
  return s + to_string(count);
} 
