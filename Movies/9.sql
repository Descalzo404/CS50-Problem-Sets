SELECT name FROM people JOIN stars on stars.person_id = people.id JOIN movies on movies.id = stars.movie_id WHERE movies.year = 2004 GROUP BY people.name ORDER BY people.birth;