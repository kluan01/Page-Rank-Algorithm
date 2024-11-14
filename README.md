IDE: CLion  
Compiler: C++17

Hi! Here is my rendition of a simplified version of the original PageRank algorithm on which Google was built by using an Adjacency List.
## To Test:
1. Clone and download dependencies found in CMakeList
2. In the first line, name the number of lines & the power iteration
3. The following lines write the website that is throwing an out-degree, then the website that is receiving the in-degree.

Example Input:
```
7 2 
google.com gmail.com
google.com maps.com
facebook.com ufl.edu
ufl.edu google.com
ufl.edu gmail.com
maps.com facebook.com
gmail.com maps.com
```

Example Output:
```
facebook.com 0.20
gmail.com 0.20
google.com 0.10
maps.com 0.30
ufl.edu 0.20
```
