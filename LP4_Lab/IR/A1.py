# from sklearn.metrics.pairwise import cosine_similarity
# from sklearn.feature_extraction.text import CountVectorizer

# document1 = "The quick brown fox jumps over the lazy dog."
# document2 = "A fast, brown fox leaps over the sleepy dog."

# documents = [document1, document2]

# vectorizer = CountVectorizer()

# X = vectorizer.fit_transform(documents)
# print(X)
# cosine_sim = cosine_similarity(X)

# print("Cosine Similarity Matrix:")
# print(cosine_sim)

# similarity_doc1_doc2 = cosine_sim[0][1]
# print(f"Similarity between document 1 and document 2: {similarity_doc1_doc2:.2f}")

import re
from collections import Counter
import math

def preprocess_text(text):
    # Tokenize the text
    words = re.findall(r'\w+', text.lower())
    # Remove stop words (you may need to define your list of stop words)
    stop_words = set(['the', 'and', 'is', 'in', 'it', 'to', 'of'])
    words = [word for word in words if word not in stop_words]
    return words

def compute_tf(text):
    word_count = Counter(text)
    total_words = len(text)
    tf = {word: count / total_words for word, count in word_count.items()}
    return tf

def compute_idf(corpus, term):
    document_count = len(corpus)
    documents_with_term = sum(1 for document in corpus if term in document)
    idf = math.log(document_count / (1 + documents_with_term))
    return idf

def compute_tf_idf(tf, idf):
    tf_idf = {word: tf_value * idf[word] for word, tf_value in tf.items()}
    return tf_idf

def cosine_similarity(doc1, doc2):
    # Calculate the dot product of the two TF-IDF vectors
    dot_product = sum(doc1[word] * doc2[word] for word in doc1 if word in doc2)
    
    # Calculate the magnitude (Euclidean norm) of each vector
    mag_doc1 = math.sqrt(sum(doc1[word] ** 2 for word in doc1))
    mag_doc2 = math.sqrt(sum(doc2[word] ** 2 for word in doc2))
    
    # Calculate the cosine similarity
    similarity = dot_product / (mag_doc1 * mag_doc2)
    return similarity

# Sample text documents
document1 = "The quick brown fox jumps over the lazy dog."
document2 = "A fast, brown fox leaps over the sleepy dog."

# Preprocess the documents
doc1_words = preprocess_text(document1)
doc2_words = preprocess_text(document2)

# Calculate TF-IDF values for each document
tf1 = compute_tf(doc1_words)
tf2 = compute_tf(doc2_words)
idf = {word: compute_idf([doc1_words, doc2_words], word) for word in set(doc1_words + doc2_words)}
tfidf1 = compute_tf_idf(tf1, idf)
tfidf2 = compute_tf_idf(tf2, idf)

# Compute cosine similarity
similarity = cosine_similarity(tfidf1, tfidf2)
print("Cosine Similarity:", similarity)
