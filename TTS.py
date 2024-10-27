import pyttsx3

class TextToSpeech:
    def __init__(self):
        self.engine = pyttsx3.init()

    def list_voices(self):
        voices = self.engine.getProperty('voices')
        for index, voice in enumerate(voices):
            print(f"Voice {index}: {voice.name} ({voice.languages})")

    def set_property(self, voice_id=None, rate=200, volume=1.0):
        self.engine.setProperty('rate', rate)
        self.engine.setProperty('volume', volume)

        # Set voice if specified
        if voice_id is not None:
            voices = self.engine.getProperty('voices')
            if 0 <= voice_id < len(voices):
                self.engine.setProperty('voice', voices[voice_id].id)
            else:
                print(f"Invalid voice ID: {voice_id}. Using default voice.")

    def speak_text(self, text):
        self.engine.say(text)
        self.engine.runAndWait()
