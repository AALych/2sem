int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new){
    if(n_new == 0){
            delete [] source;
        return NULL;
    }
    int* ans = new int[n_new];
    if(source!=NULL){
        for(int i=0; i< std::min(n_old, n_new); i++){
            ans[i]=source[i];
        }
        delete[] source;
    }
    return ans;
}
