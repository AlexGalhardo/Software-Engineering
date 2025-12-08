# Large JSON file process with Streams

Downloading a large JSON file and saving its content to Database using:

- No stream, download full JSON and insert one-by-one on database;
- Stream download and insert one-by-one on database;
- Stream download and insert in batches on database;

## No Streams

Memory usage: 537.05MB

Executed in    9.23 secs    fish           external
   usr time   11.99 secs   82.00 micros   11.99 secs
   sys time    2.21 secs  473.00 micros    2.21 secs

## Insert one-by-one

Memory usage: 19MB

Executed in    9.80 secs    fish           external
   usr time   12.96 secs   63.00 micros   12.96 secs
   sys time    1.86 secs  850.00 micros    1.85 secs

## Insert in batches (1000)

Memory usage: 58MB

Executed in    3.67 secs    fish           external
   usr time    3.33 secs   16.40 millis    3.31 secs
   sys time    0.23 secs    3.46 millis    0.23 secs

