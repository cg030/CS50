SELECT title, season
FROM episodes
WHERE (season, episode_in_season)
IN (SELECT season, MIN(episode_in_season)
    FROM episodes
    GROUP BY season);