import React, { useState } from 'react'
import { Box } from '@site/src/algorithms/ui/box/box'
import Translate from '@docusaurus/Translate'
import { Debugger } from '../../ui/debugger/debugger'
import styles from './styles.module.css'

interface LinearArraySearchProps {
  array: number[]
  element: number
}

export function LinearArraySearch ({ array, element }: LinearArraySearchProps) {
  const [currentIndex, setCurrentIndex] = useState(-1)

  const handleNext = () => {
    if (currentIndex < array.length - 1 && array[currentIndex] !== element) {
      setCurrentIndex(currentIndex + 1)
    }
  }

  const handlePrevious = () => {
    if (currentIndex > -1) {
      setCurrentIndex(currentIndex - 1)
    }
  }

  const isBoxActive = (boxIndex: number) => currentIndex === boxIndex && array[currentIndex] === element
  const isBoxCurrent = (boxIndex: number) => currentIndex === boxIndex

  const isNextButtonDisabled = currentIndex === array.length - 1 || array[currentIndex] === element
  const isPreviousButtonDisabled = currentIndex === -1

  return (
    <div style={{ display: 'flex' }}>
      <div style={{ width: '50%' }}>
        <div className={styles.boxContainer}>
          {array.map((value, index) => (
            <div key={index} className={styles.boxItemsContainer}>
              <p style={{ marginBottom: 0 }}>{index}</p>
              <Box
                isActive={isBoxActive(index)}
                isCurrent={isBoxCurrent(index)}
              >
                {value}
              </Box>
            </div>
          ))}
        </div>
        <div className={styles.buttonContainer}>
          <button className="button button--secondary" onClick={handlePrevious} disabled={isPreviousButtonDisabled}>
            <Translate id="algorithm.actions.previous">
              Previous
            </Translate>
          </button>
          <button className="button button--secondary" onClick={handleNext} disabled={isNextButtonDisabled}>
            <Translate id="algorithm.actions.next">
              Next
            </Translate>
          </button>
        </div>
        <div>
          {currentIndex > -1 ? (
            <>
              <p>
                <Translate id="algorithm.linearArraySearch.isItEqual_1">
                  Is it
                </Translate>
                {array[currentIndex]}
                <Translate id="algorithm.linearArraySearch.isItEqual_2">
                  equal to
                </Translate>
                {element}?</p>
              {array[currentIndex] === element ? (
              <p>
                <Translate id="algorithm.linearArraySearch.match">
                  Yes! Return the index of this position
                </Translate>
                ({currentIndex}).</p>
              ) : currentIndex === array.length - 1 ? (
                <p>
                  <Translate id="algorithm.linearArraySearch.endOfArray">
                    No, end of the array reached, return -1.
                  </Translate>
                </p>
              ) : (
                <p>
                  <Translate id="algorithm.linearArraySearch.notMatch">
                    No, go to the next element.
                  </Translate>
                </p>
                ) }
            </>
          ) : (
            <>
              <p>
                <Translate id="algorithm.actions.startDescription">
                  Click on next to start the algorithm.
                </Translate>
              </p>
              <p>
                <Translate id="algorithm.actions.stepLogicDescription">
                  The logic for each step will be displayed here.
                </Translate>
              </p>
            </>
          )}
        </div>
      </div>
      <div style={{ width: '50%' }}>
        <h3>Debugger</h3>
        <Debugger>
          <p>--------------------------</p>
          {currentIndex > -1 ? <p>index: {currentIndex}</p> : <p>index: null</p>}
          {currentIndex > -1 ? <p>current element: {array[currentIndex]}</p> : <p>current element: null</p>}
          {<p>target element: {element}</p>}
          {array[currentIndex] === element ? <p>return value: {currentIndex}</p> : currentIndex === array.length - 1 ? <p>return value: -1</p> : <p>return value: pending</p>}
          <p>--------------------------</p>
        </Debugger>
      </div>
    </div>
  )
}
