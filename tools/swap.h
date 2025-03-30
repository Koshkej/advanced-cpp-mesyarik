namespace custom {
    
    template <typename T> 
        void swap (T* l, T* r) {
            T buff = *l;
            *l = *r;
            *r = buff;
        }

}
