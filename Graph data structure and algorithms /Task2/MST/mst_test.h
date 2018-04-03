#include <gtest/gtest.h>
#include "Graph.h"
#ifndef MST_MST_TEST_H
#define MST_MST_TEST_H

TEST (MST_TEST, CheckMST_1){
   Graph TestGraph(3,3);
    TestGraph.graph= {
            {1,2,1},
            {2,3,2},
            {3,1,3}
    };
    int res = TestGraph.MST();

    ASSERT_EQ(res, 3);
}
TEST (MST_TEST, CheckMST_2){
    Graph TestGraph(8,13);
    TestGraph.graph= {
            {1,2,1},
            {2,4,3},
            {4,3,7},
            {3,6,9},
            {5,6,6},
            {6,7,4},
            {7,8,2},
            {8,1,1},
            {8,2,13},
            {1,6,2},
            {7,4,5},
            {1,3,3},
            {2,3,5}

    };
    int res = TestGraph.MST();

    ASSERT_EQ(res, 18);
}
TEST (MST_TEST, CheckMST_3){
    Graph TestGraph(4,4);
    TestGraph.graph= {
            {1,2,2},
            {2,3,2},
            {3,4,2},
            {4,1,2},
            {2,4,3}
    };
    int res = TestGraph.MST();

    ASSERT_EQ(res, 6);
}
TEST (MST_TEST, CheckMST_4){
    Graph TestGraph(8,8);
    TestGraph.graph= {
            {1,2,1},
            {2,4,3},
            {4,3,7},
            {3,6,9},
            {5,6,6},
            {6,7,4},
            {7,8,2},
            {8,1,1}

    };
    int res = TestGraph.MST();
    ASSERT_EQ(res, 24);
}

#endif //MST_MST_TEST_H
