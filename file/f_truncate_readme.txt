
1: this is example of how to store all parameters to a file
   these parameter include like: 
   	1): input buffer data, input buffer length
	2): output buffer data, output buffer length
	3): paramete flags
	
In a word, store everything input
then use another function to truncate the data,flag out, respectively

2: steps: 
 a: use randnum function generate data, length, and flags
 b: store them to one file: data.in (we need store these parameter to
 each file, respectively, for the later comparition)
 c: truncate data according to the length, flag

3: compare truncated data with preview stored data

4: 
