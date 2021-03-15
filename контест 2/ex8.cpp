Cat* get_home_for_a_cats_pride(unsigned int n){
    Cat* ans = new Cat[n];
    for(int i=0;i<n;i++){
        ans[i].name = new char[10];
    }
    return ans;
}

void clear_home_of_a_cats_pride(Cat *cats, unsigned int n){
    for(int i=0;i<n;i++){
        delete[] cats[i].name;
    }
    delete[] cats;
}
