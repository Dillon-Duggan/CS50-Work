SELECT AVG(energy) FROM songs, artists
WHERE artist_id = artists.id
AND artists.name = 'Drake';