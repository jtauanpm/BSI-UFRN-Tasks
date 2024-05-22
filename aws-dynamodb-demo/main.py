from fastapi import FastAPI 
from botocore.exceptions import ClientError
import boto3

app = FastAPI()


@app.get("/")
def index():
    dynamodb = boto3.resource('dynamodb')
    books_table = dynamodb.Table('Books')

    response = books_table.scan()
    
    return response['Items']

@app.get("/{book_id}")
def get(book_id):
    dynamodb = boto3.resource('dynamodb')
    books_table = dynamodb.Table('Books')

    try:
        response = books_table.get_item(
            Key={'book_id': book_id}
        )
    except ClientError as e:
        print(e.response['No item found'])
    else:
        return response['Item']

@app.post("/")
def create():
    dynamodb = boto3.resource('dynamodb')
    books_table = dynamodb.Table('Books')

    response = books_table.put_item(
        Item={
            "book_id": 1005,
            "title": "There Was a Country",
            "author": "Chinua Achebe",
            "isbn": "0143124030",
            "year_of_publication": "2012"
        }
    )

    return response

@app.delete("/{book_id}")
def deletar(book_id):
    dynamodb = boto3.resource('dynamodb')
    books_table = dynamodb.Table('Books')

    response = books_table.delete_item(
        Key={
            'book_id' : book_id,
        },
    )

    return response

@app.put("/{book_id}")
def update(book_id):
    dynamodb = boto3.resource('dynamodb')
    books_table = dynamodb.Table('Books')

    response = books_table.update_item(
        Key={
            'book_id' : book_id,
            'title': "Americanah"
        },
        UpdateExpression="set ISBN=:ISBN",
        ExpressionAttributeValues={':ISBN': "9780307455925"},
        ReturnValues="UPDATED_NEW"
    )

    return response


