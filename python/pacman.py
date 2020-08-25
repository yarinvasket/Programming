import gym

env = gym.make('MsPacman-v0')
for i_episode in range(100):
    observation = env.reset()
    while True:
        env.render()
        action = env.action_space.sample()
        observation, reward, done, info = env.step(action)
        if done:
            break
env.close()