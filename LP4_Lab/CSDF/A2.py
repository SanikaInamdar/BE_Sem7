from PIL import Image, ImageDraw, ImageFont
import random

# Generate a random CAPTCHA text
def generate_captcha_text():
    characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
    captcha_text = ''.join(random.choice(characters) for _ in range(6))
    return captcha_text

# Create a CAPTCHA image
def create_captcha_image(captcha_text):
    width, height = 200, 80
    background_color = (255, 255, 255)
    text_color = (0, 0, 0)

    image = Image.new('RGB', (width, height), background_color)
    draw = ImageDraw.Draw(image)
    font = ImageFont.load_default()  # Use the default system font

    # Add text to the image with random distortion
    for i in range(6):
        char = captcha_text[i]
        x = 10 + i * 30 + random.randint(-5, 5)
        y = random.randint(10, 20)
        draw.text((x, y), char, fill=text_color, font=font)

    # Add noise to the image
    for _ in range(100):
        x = random.randint(0, width - 1)
        y = random.randint(0, height - 1)
        draw.point((x, y), fill=text_color)

    image.save("captcha.png")
    image.show()

# Verify the user's input against the generated text
def verify_captcha(input_text, captcha_text):
    return input_text == captcha_text

if __name__ == "__main__":
    captcha_text = generate_captcha_text()
    create_captcha_image(captcha_text)

    user_input = input("Enter the CAPTCHA text: ")
    if verify_captcha(user_input, captcha_text):
        print("CAPTCHA is correct. You are a human!")
    else:
        print("CAPTCHA is incorrect. You might be a bot!")
