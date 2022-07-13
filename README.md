# Amazon Data Manipulation Application

##Overview:

In this Project, we have dealt with "Big Dataset" and
through efficient use of Data Structure, we have
manipulated the dataset and obtained the best time
complexity for it.
To Explain, we have used "B+ Trees" for the dataset that
amounts for 1.8Gb in size and 2 millions+ in records.
Since the B+ tree is a m-ary tree, we have efficiently
increased the height to the optimal level through which
time complexity reduced to less than O(logn).

Details:

## Login Component:

we have integrated a secure login component in our
project, in which only authorized user (Admin) can
manipulate the data. The component is password-protected.

-TOP PRODUCTS
-WORST PRODUCTS
-BEST PRICE PRODUCTS
-SEARCH PRODUCTS
-DISPLAY PRODUCTS
## Entertainment Component:

Here we have two categories: Movies&Tv and Music. Both of
these sums up to the size of 1.2Gb.
Both of them have the features like:

-TOP PRODUCTS
-WORST PRODUCTS
-BEST PRICE PRODUCTS
-SEARCH PRODUCTS
-DISPLAY PRODUCTS

## Technology Component:

Here we have two categories: Software and Video Games .
In the dataset, we have unsorted software's id, prices and
ratings and reviews.
Both of them have the features like:

With manipulating the data, Admin can see the best
products, worst products, best price product ( in terms of
price and rating) and can perform searching for a provided
"Id". Top , worst and best product are found based on the
users, reviews and rating.

## TIME COMPLEXITY O(logn):

The best time complexity for big data can only be achieved
through trees especially BST. What about more dynamic (in
terms of its branching) and self-balancing BST? Here,
B+Trees comes into the picture to serve our needs. For 2M+
Data, B+ tree still gives us the best searching time
complexity of O(logn) unlike Hashing and other searching
data structure. Same is the case for data insertion in B+
trees.
