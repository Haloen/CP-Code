#ifndef segtree.h
#define segtree.h

namespace OOP_Competitive_Programming {

    template<typename T>
    class seg_tree {
        private:
            int num_nodes;
        
            //Array Segment Tree
            template<typename U>
            struct node {

                int s, e, m;
                U value;

                node(int, int);

                update(int, U);
                query(int, int);

            };
            
            // Root node
            node<T> *node_value;

            //Function for getting the value from the child
            T *f (T, T);

        public:

            //Default Ctor
            seg_tree(int = 0, int = 0, T (*)(T, T) = std::min);

            //Copy Ctor
            seg_tree(seg_tree const&);

            //Copy Assignment Operator
            seg_tree& operator=(seg_tree const&);

            //Destructor
            ~seg_tree();

            void update(int, T);

            T query(int, int);

            T (*)(T, T) getValueFunction();
            int getSize();
    }; // End of seg_tree class

} // End of namespace CP

#endif