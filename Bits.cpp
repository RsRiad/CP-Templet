int getIthBit(int n, int i){
    int mask = (1<<i);
    return (n & mask) > 0 ? 1 : 0 ;
}
void setIthBit(int &n, int i){
    int mask = (1<<i);
    n = ( n | mask );
}
void clearIthBit(int &n,int i){
    int mask = ~(1<<i);
    n = n & mask;
}
void updateIthBit(int n,int ind,int bit){
    clearIthBit(n,ind);
    int mask = (bit<<ind);
    n = (n | mask);
}
void clearLastIBits(int &n , int i){
    int mask = (-1<<i);
    n = ( n & mask );
}
void clearBitsInRange(int &n,int i, int j){
    int a = (~0)<<(j+1) ;
    int b = (1<<i)-1 ;
    int mask = a | b;
    n = ( n & mask ) ;
}
void toggleIthBit(int &n, int i){
    int mask = (1<<i);
    n = n^(1<<i);
}

//__builtin_popcount()    //[ x is in integer ]
//__builtin_popcountll()  //[ x is in long long ]
