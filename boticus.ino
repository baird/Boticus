const int sensorPin = 0;
const int ledPin = 9;
int lightLevel, high = 0, low = 1023;

const int buzzerPin = 13;
const int songLength = 19;

//char notes[] = "cdfda ag cdfdg gf "; // a space represents a rest
char notes[] = "eeee dddd eeee dddd"; // a space represents a rest

//int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int beats[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int tempo = 150;

void setup()

{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

// MAIN LOOP
void loop()
{
  lightLevel = analogRead(sensorPin);

  manualTune();

  analogWrite(ledPin, lightLevel);

/*
  
  // Wakeup Tones

  int i, duration;

  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms

    if (notes[i] == ' ')          // is this a rest?
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo / 10);            // brief pause between notes
  }

  // We only want to play the song once, so we'll pause forever:
  while (true) {}
  // If you'd like your song to play over and over,
  // remove the above statement

}

*/

// VOID MANUAL PHOTOSENSOR TUNING
void manualTune()
{
  lightLevel = map(lightLevel, 950, 650, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}


// NOTES
int frequency(char note)
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.

  int i;
  const int numNotes = 8;  // number of notes we're storing

  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return (frequencies[i]);    // Yes! Return the frequency
    }
  }
  return (0); // We looked through everything and didn't find it,
  // but we still need to return a value, so return 0.
}

