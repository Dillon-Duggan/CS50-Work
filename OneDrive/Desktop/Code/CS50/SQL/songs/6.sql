SELECT songs.name FROM songs, artists
WHERE artist_id = artists.id
AND artists.name = 'Post Malone';